if File.exists?("input.txt")
  file = File.open("input.txt")
  file_data = file.read
  file.close
else
  file_data = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"
end

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
