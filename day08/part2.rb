require 'set'

if File.exists?("input.txt")
  file = File.open("input.txt")
  file_data = file.read
  file.close
else
  file_data = "............\n........0...\n.....0......\n.......0....\n....0.......\n......A.....\n............\n............\n........A...\n.........A..\n............\n............"
end

antennas = []
map = file_data.split("\n")
map.each_with_index do |row, r|
  row.chars.each_with_index do |char, c|
    antennas << [c, r, char] if char != '.'
  end
end

antinodes = Set.new

antennas.each_with_index do |(x1, y1, value1), i|
  antennas.each_with_index do |(x2, y2, value2), j|
    next if i == j
    next unless  value1 == value2

    x_dir = x2 - x1
    y_dir = y2 - y1

    [1, -1].each do |dir|
        x_point = x1
        y_point = y1

      loop do
        x_point = x_point - x_dir * dir
        y_point = y_point - y_dir * dir

        if (!x_point.between?(0, map.size - 1) || !y_point.between?(0, map[0].size - 1))
          break
        end

       antinodes.add([x_point, y_point])
      end
    end
  end
end

puts antinodes.size
