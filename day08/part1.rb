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
      if dir > 0
        x_point = x1 - x_dir * dir
      else
        x_point = x2 - x_dir * dir
      end
      
      if dir > 0
        y_point = y1 - y_dir * dir
      else
        y_point = y2 - y_dir * dir
      end

      antinodes.add([x_point, y_point]) if (x_point.between?(0, map.size - 1) && y_point.between?(0, map[0].size - 1))
    end
  end
end

puts antinodes.size
