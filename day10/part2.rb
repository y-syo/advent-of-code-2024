require 'set'

def find_trailheads(grid)
  trailheads = []
  grid.each_with_index do |row, y|
    row.each_char.with_index do |height, x|
      trailheads << [x, y] if height == '0'
    end
  end
  trailheads
end

def find_path(grid, x, y, visited)
  score = 0

  return 1 if grid[y][x] == '9'

  visited.add([x, y])

  [[-1, 0], [1, 0], [0, -1], [0, 1]].each do |x_dir, y_dir|
    nx, ny = x + x_dir, y + y_dir
    next unless ny.between?(0, grid.size - 1) && nx.between?(0, grid[0].length - 1)
    next if visited.include?([nx, ny])
    
    if grid[ny][nx].to_i == grid[y][x].to_i + 1
      score += find_path(grid, nx, ny, visited)
    end
  end

  visited.delete([x, y])
  score
end



if File.exists?("input.txt")
  file = File.open("input.txt")
  file_data = file.read
  file.close
else
  file_data = "89010123\n78121874\n87430965\n96549874\n45678903\n32019012\n01329801\n10456732"
end

grid = file_data.split("\n")

trailheads = find_trailheads(grid)
result = 0

trailheads.each do |trailhead|
  result += find_path(grid, trailhead[0], trailhead[1], Set.new)
  #puts result
end

puts "result : #{result}"
