

f = open('map.txt','r')
out = []
for l in f.readlines():
	s = int(l[l.find('= ')+2:l.find(';')])
	out.append(s)
f.close()

f = open('map.dat','w')
for i, k in enumerate(out):
	f.writelines('%d'%k)
	if ((i+1)%9==0 and i!=0):
		f.writelines('\n')
	else:
		f.writelines(',')
f.close()