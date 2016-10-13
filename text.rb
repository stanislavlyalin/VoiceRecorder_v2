# encoding: utf-8
data = File.open('War and peace.txt').read.force_encoding('utf-8')
pattern = /[А-Я]{1}[А-Яа-я ,]+\./
data.scan(pattern).each do |sentence|
  puts "    \"#{sentence}\"," if sentence.size.between?(100, 140)
end