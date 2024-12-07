if File.exists?("input.txt")
  file = File.open("input.txt")
  file_data = file.read
  file.close
else
  file_data = "190: 10 19\n3267: 81 40 27\n83: 17 5\n156: 15 6\n7290: 6 8 6 15\n161011: 16 10 13\n192: 17 8 14\n21037: 9 7 18 13\n292: 11 6 16 20"
end

def eval_left_to_right(expression)
  tokens = expression.split(/(\+|\*|\|\|)/).map(&:strip)

  result = tokens.shift.to_i
  until tokens.empty?
    operator = tokens.shift
    operand = tokens.shift.to_i

    if (operator == '||')
      result = (result.to_s + operand.to_s).to_i
    else
      result = result.send(operator, operand)
    end
  end

  result
end

#puts file_data
data_array = file_data.split("\n")
results = []
values = []

for line in data_array do
  res, val = line.split(":").map(&:strip)
  res = res.to_i
  val = val.split.map(&:to_i)
  results.push(res)
  values.push(val)
end

puts results.inspect
puts values.inspect

res = 0
operations = ['+', '*', '||']

results.each_with_index do |result, index|
  #puts "\nindex: #{index} | #{result} : #{values[index]}"

  combinations = operations.repeated_permutation(values[index].length - 1).to_a

  combinations.each do |comb|
    expr = values[index].zip(comb).flatten.compact.join
    #puts "#{expr} = #{eval_left_to_right(expr)}"

    if eval_left_to_right(expr) == result
      #puts "#{result}"
      res += result
      break
    end

  end
end

puts res
