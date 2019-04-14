def solution(A):
    # write your code in Python 3.6
    freq = {}
    # die_list = [x for x in range(1,7)]
    sum_list = []
    for i in range(1,7):
        freq[i] = A.count(i)


    for k in range(1,7):
        die_list = [x for x in range(1,7)]
        die_list.remove(k)
        die_list.remove(7-k)
        side_list = die_list

        sum = 0
        for s in side_list:
            sum = sum + freq[s]
        sum = sum + freq[7-k]*2
        sum_list.append(sum)
    return (min(sum_list))
    


if __name__=="__main__":
    num = solution([1,1,1,1,1,1,6])
    print(num)