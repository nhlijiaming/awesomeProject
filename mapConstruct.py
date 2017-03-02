import scanf


file = open("temp.cpp","a")
i = 0
while(True):
	s = raw_input("input mapdata:")
	if (s==""):
		break;
	d = scanf.sscanf(s, "%d %d %d %d %d %d %d %d")
	file.writelines("gridMap[%d][0] = %d; \ngridMap[%d][1] = %d; \ngridMap[%d][2] = %d; \n\
gridMap[%d][3] = %d; \ngridMap[%d][4] = %d; \ngridMap[%d][5] = %d; \n\
gridMap[%d][6] = %d; \ngridMap[%d][7] = %d; \ngridMap[%d][8] = %d; \n\n"%(i, i, i, d[0], i, d[1], i, d[2], i, d[3], i, d[4], i, d[5], i, d[6], i, d[7]))
	i = i + 1
file.close()