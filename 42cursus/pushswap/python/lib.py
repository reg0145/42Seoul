def get_prev(target):
	data = -1
	prev = -1
	if g_A:
		data = target
	if data == g_start:
		prev = g_end
	else:
		prev = data - 1
	return prev

def check_prev(prev):
	num = -1
	flag = 1
	for i in g_A:
		if prev != i and flag:
			continue
		flag = 1
		if prev > i:
			return 0
	return 1

def processA(A, B, start, end, big):
	global g_A
	global g_B
	global g_start
	global g_end

	g_A = A
	g_B = B
	g_start = start
	g_end = end
	prev = get_prev(A[0])

	if g_A[0] > g_A[1]:
		if len(B) >= 2 and g_B[0] < g_B[1]:
			return 'ss'
		return 'sa'
	elif prev in g_B or prev == A[-1]:
		return 'ra'
	else:
		return 'pb'

def processB(A, B, start, end):
	return
