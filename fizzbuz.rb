NUM_STUDENTS = 20

# 平均点の計算
def calculate_mean(scores)
  scores.sum.to_f / NUM_STUDENTS
end

# 標準偏差の計算
def calculate_standard_deviation(scores, mean)
  squared_diff = scores.map { |score| (score - mean) ** 2 }
  Math.sqrt(squared_diff.sum / NUM_STUDENTS)
end

# 偏差値の計算
def calculate_z_scores(scores, mean, stddev)
  scores.map { |score| (score - mean) / stddev * 10 + 50 }
end

# 配列を降順に並べ替え
def sort_scores_descending(scores)
  scores.sort.reverse
end

# 理科と英語の点数
science_scores = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
english_scores = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

# 平均点の計算
science_mean = calculate_mean(science_scores)
english_mean = calculate_mean(english_scores)

# 標準偏差の計算
science_stddev = calculate_standard_deviation(science_scores, science_mean)
english_stddev = calculate_standard_deviation(english_scores, english_mean)

# 偏差値の計算
science_z_scores = calculate_z_scores(science_scores, science_mean, science_stddev)
english_z_scores = calculate_z_scores(english_scores, english_mean, english_stddev)

# 合計点の計算
total_scores = science_scores.zip(english_scores).map { |science, english| science + english }

# 点数の高い順に並び替え
sorted_total_scores = sort_scores_descending(total_scores)

# 結果の表示
puts "理科 平均点: #{science_mean.round(2)}, 標準偏差: #{science_stddev.round(2)}"
puts "英語 平均点: #{english_mean.round(2)}, 標準偏差: #{english_stddev.round(2)}"

puts "\n各学生の点数と偏差値:"
puts " 学生 | 理科 | 英語 | 合計 | 理科偏差値 | 英語偏差値"
puts "--------------------------------------------------"
NUM_STUDENTS.times do |i|
  puts format("  %2d   |  %2d  |  %2d  |  %2d  |    %.2f    |    %.2f",
              i + 1, science_scores[i], english_scores[i], total_scores[i],
              science_z_scores[i], english_z_scores[i])
end

puts "\n点数の高い順に並べ替えた合計点:"
puts sorted_total_scores
