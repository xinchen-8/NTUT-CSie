population = int(input())           #n
period = int(input())               #m
first_diagnosed = int(input())      #a:ave_one_infect_num = (b/c)*(1-d)
infect = float(input())             #b:int(nextday_add) = today_diagnsnosed*ave_one_infect_num
recover = int(input())              #c
immunity = float(input())           #d:next_d=d+today_recover_num/n
infect_of_upperlimit = int(population*(1-immunity))


diagnosed = [0]
add_diagnosed = [0,first_diagnosed]
for day in range(1,period+1):

    if day==1:
        total = first_diagnosed
        today_infect = first_diagnosed
        diagnosed.append(first_diagnosed)
    else:
        today_infect = int((diagnosed[day-1])*(infect/recover)*(1-immunity))
        if today_infect+total>=infect_of_upperlimit:
            today_infect = infect_of_upperlimit - total
            total = infect_of_upperlimit
        else:
            total += today_infect
        add_diagnosed.append(today_infect)
        immunity += (diagnosed[day-recover]-diagnosed[day-recover-1])/population if day-recover-1>=0 else 0
        diagnosed.append(diagnosed[day-1]+today_infect-(add_diagnosed[day-recover])if day-recover-1>=0 else diagnosed[day-1]+today_infect)
    print(f'{day} {diagnosed[day]} {today_infect} {add_diagnosed[day-recover]if day-recover-1>=0 else 0}')
print(total)