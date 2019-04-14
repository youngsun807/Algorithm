def solution(T):
    # write your code in Python 3.6
    summer_list = T.copy()
    winter_list = []
    winter_list.append(summer_list[0])
    summer_list.remove(summer_list[0])
    
    for i in range(len(T)-1):
        if(len(summer_list) > 1):
            print("summer_list는 ", summer_list)
            if(max(winter_list)>=min(summer_list)):
                print("winter_list 최대값 : ", max(winter_list))
                print("summer_list 최소값 : ", min(summer_list))
                winter_list.append(min(summer_list))
                summer_list.remove(min(summer_list))
            elif(max(winter_list)==min(summer_list)):
                pass
            else:
                break
        else:
            break
    
    return(len(winter_list))
    
if __name__=="__main__":
    T = [5,-2,3,8,6]
    length = solution(T)
    print(length)