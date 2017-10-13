s = raw_input()
n = int(s.split()[0])
k = int(s.split()[1])
res = ''

sum = 0
level = 0
opened = 0

while level > -1:
	if sum + level <= k and opened < n:
		sum = sum + level
		res = res + '('
		opened = opened + 1
		level = level + 1;
	else:
		if level > 0:
			res = res + ')'
		level = level - 1

if sum == k and opened == n and level < 0:
	print (res)
else:
	print ('Impossible')
