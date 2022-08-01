import random
import copy
import numpy as np
import lib2
from collections import deque


def pa():
	if B:
		data = B.popleft();
		A.appendleft(data);

def pb():
	if A:
		data = A.popleft();
		B.appendleft(data);

def sa():
	length = len(A);
	if length >= 2:
		tmp = A[0];
		A[0] = A[1];
		A[1] = tmp;
	return A;

def rra():
	result = [];
	if A:
		data = A.pop();
		A.appendleft(data);
		result = list(A);
	return result;

def ra():
	result = [];
	if A:
		data = A.popleft();
		A.append(data);
	return A;

def sb():
	length = len(B);
	if length >= 2:
		tmp = B[0];
		B[0] = B[1];
		B[1] = tmp;
	return A;

def rrb():
	result = [];
	if B:
		data = B.pop();
		B.appendleft(data);
		result = list(B);
	return result;

def rb():
	result = [];
	if B:
		data = B.popleft();
		B.append(data);
	return B;

def change_data(A, _len):
	if _len >= 2:
		if A[0] > A[1]:
			lib2._sa(A)

def find_total_distance(num):
	global total
	cost_ra = 0;
	cost_rra = 0;
	A_ra = copy.deepcopy(A)
	A_rra = copy.deepcopy(A)
	i = 0
	A_len = len(A)
	while (i < A_len):
		if num == A_ra[0]:
			break
		lib2._ra(A_ra);
		cost_ra+=1
		i+=1
	i = 0
	while (i < A_len):
		if num == A_rra[0]:
			break

		lib2._rra(A_rra);
		cost_rra+=1
		i+=1

	if cost_ra > cost_rra:
		print(num, " : ", cost_rra, "rra")
		total += cost_rra
		return A_rra
	else:
		print(num, " : ", cost_ra, "ra")
		total += cost_ra
		return A_ra

def find_range_cost(num, ran):
	l_rra = []
	l_ra = []
	A_len = len(A)
	for i in range(num, num + ran):
		cost = 0
		for j in A:
			if i == j:
				break
			cost += 1
		if cost > A_len / 2:
			l_rra.append(A_len - cost)
		else :
			l_ra.append(cost)
	l_ra.sort()
	l_rra.sort(reverse=True)
	print(l_rra, l_ra)

global dic
global A,B,C

dic = {ra:rra, rra:ra, pa:pb, pb:pa, sa:sa};
command = {'pa':pa, 'pb':pb, 'sa':sa, 'sb':sb, 'ra':ra, 'rb':rb, 'rra':rra, 'rrb':rrb}
start = 1
end = 100
A = deque(range(start, end + 1))
B = deque([])
total = 0
cur_list = []
pb
random.shuffle(A)
count = 0;
idx = 1
A_len = len(A)
print(A)
find_range_cost(A_len / 2, 5)
find_range_cost(A_len / 2, 5)
""""
while (idx < end):
	A = find_total_distance(idx)
	pb()
	idx+=1
print(total)
"""
while (1) :
	print(A, count)
	if B:
		print(B)
	s = input("명령어 : ")
	if s in command:
		command[s]();
		count += 1
