import random
import copy
import lib
import numpy as np
from collections import deque

def ss():
	sa()
	sb()

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

def find_bignum_queue(q):
	big = q[0]
	for i in q:
		if big < i:
			big = i
	return big

def find_smallnum_queue(q):
	small = q[0]
	for i in q:
		if small > i:
			small = i
	return small

def check_flow(end):
	prev = A[0]
	count = 0
	big = find_bignum_queue(A)
	small = find_smallnum_queue(A)
	plu_flag = -1
	min_flag = -1
	for i in A:
		if i == prev:
			continue
		if plu_flag:
			tmp = plu_flag
			plu_flag = -1
			if i == tmp - 1:
				prev = tmp
		if prev == big:
			prev = 0
		# 2 4 3 5
		if prev + 1 < i:
			for j in range(prev + 1, i + 1):
				if j not in B:
					count += 1
					break
		if count:
			break
		prev = i
	return count

global dic;
global A,B;
global command;
dic = {ra:rra, rra:ra, pa:pb, pb:pa, sa:sa};
command = {'ss':ss, 'pa':pa, 'pb':pb, 'sa':sa, 'sb':sb, 'ra':ra, 'rb':rb, 'rra':rra, 'rrb':rrb}
start = 1
end = 10
A = deque(range(start, end))
#A = deque([1,3,2])
B = deque([])
cur_list = []
random.shuffle(A)
count = 0
end -= 1
end_point = 1
end_data = A[-1]

print(A)
while (check_flow(end) and end_point):
	if end_data == A[0]:
		end_point = 0
	big = find_bignum_queue(A)
	c = lib.processA(A, B, start, end, big)
	print(c)
	command[c]()
	count += 1
	print(A)
	if B:
		print(B)
	"""
	s = input("명령어 : ")
	if s in command:
		command[s]();
		count += 1
	"""
print(count)
