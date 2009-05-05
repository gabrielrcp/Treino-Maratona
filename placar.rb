#!/usr/bin/env ruby

require 'net/http'
require 'uri'

Server = "http://bombonera.ime.usp.br:8180/gtreino/"

def parse_points(html) 
    ret = Hash.new

    html.gsub!(/<[^>]*>/,'').gsub!(/[\t]/,'').strip!.gsub!(/\n[\n]*/,"\n")
    cnt = -1
    n = q = String.new

    html.each_line do |l|
        if cnt >= 0
            n = l if cnt % 3 == 0
            q = l.to_i; ret[n.chomp] = q if cnt % 3 == 1
            cnt += 1
        end

        cnt = 0 if l.match("NomeResolvidos")
    end

    return ret
end

def le_senha
    system "stty -echo"
    print "Password: "
    pw = STDIN.gets.chomp
    puts ""
    system "stty echo"
    return pw
end

def get_placar(username, senha, id)
    printf "Obtendo o placar da competição com id #{id} ..."

    # connext to the server
    url = URI.parse(Server)
    http = Net::HTTP.new(url.host, url.port)
    http.start

    # post login
    url = URI.parse(Server + "admin.efetuaLogin.logic")
    request = Net::HTTP::Post.new(url.path)
    request.set_form_data({'usuario.nome'=>username,
                        'usuario.senha'=>senha,
                        'redireciona'=>''})

    resp, data = http.request(request)

    if data.index("logout") == nil
        puts "Login failed"
        return 0
    end

    # get cookies
    cookie = resp['set-cookie']

    # url = URI.parse(Server + "competicao.gerenciador.logic?competicao.id=18")
    request = Net::HTTP::Get.new("/gtreino/competicao.gerenciador.logic?competicao.id=#{id}")
    request.add_field("Cookie", cookie)

    resp, data = http.request(request)

    printf " DONE!\n"

    return parse_points(data)
end

if ARGV.size() != 1
	puts "Como usar: ./placar.rb <nome_de_usario_gtreino>"
	exit
end

# Id's das competições individuais, 2 pontos somados por cada problema
competicoes = [17, 24, 21, 23, 26]

# Id do placar geral, 1 ponto somado por cada problema
geral = 18

senha = le_senha
username = ARGV[0]

pontos = get_placar(username, senha, geral)

competicoes.each do |i|
    tmp = get_placar(username, senha, i)
    tmp.each do |i,j|
        if pontos.key?(i)
            pontos[i] += j*2
        else
            pontos[i] = j*2
        end
    end
end

lista = []

pontos.each do |i,j|
    lista << [j,i]
end

lista.sort!.reverse!

puts "\n=== Placar Geral ===\n"
apontos = -1
pos = 0
contador = 0
lista.each do |i, j|
    contador += 1
    pos = contador if apontos != i
    apontos = i
    printf("%3d %3d %s\n", pos, i, j)
end
puts ""


