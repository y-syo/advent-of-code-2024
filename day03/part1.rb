file = File.open("input.txt")
file_data = file.read
file.close

#puts file_data
sane_data = file_data.scan(/mul\(\d+,\d+\)/)
#puts sane_data.inspect

numbers = sane_data.map do |item|
  item.scan(/\d+/).map(&:to_i)
end
#puts numbers.inspect

result = 0

for mul in numbers do
  result = result + mul[0] * mul[1]
end

puts result
