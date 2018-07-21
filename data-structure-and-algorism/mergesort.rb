# frozen_string_literal: true

def mergesort(arr)
  return arr if arr.count < 2

  m = arr.count / 2
  left = mergesort(arr.slice(0, m))
  right = mergesort(arr.slice(m, arr.count))

  tmp = []
  loop do
    if left.empty?
      return tmp + right
    elsif right.empty?
      return tmp + left
    end

    if left[0] <= right[0]
      tmp << left.shift
    else
      tmp << right.shift
    end
  end
end

input = gets.split(" ")
p mergesort(input)
