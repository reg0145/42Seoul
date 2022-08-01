import random
import copy
import numpy as np
from collections import deque


def pushB(A, B):
	if A:
		data = A.popleft();
		B.append(data);

def pushA(A, B):
	if B:
		data = B.popleft();
		A.append(data);

def sa(deq):
	length = len(deq);
	if length >= 2:
		tmp = deq[0];
		deq[0] = deq[1];
		deq[1] = tmp;
	return deq;

def rra(deq):
	result = [];
	if deq:
		data = deq.pop();
		deq.appendleft(data);
		result = list(deq);
	return result;

def ra(deq):
	result = [];
	if deq:
		data = deq.popleft();
		deq.append(data);
	return deq;

def calc_cost(lst, command = None):
	result = deque([]);
	if command != None:
		lst = command(copy.deepcopy(lst));
	length = len(lst);
	i = 1;
	for l in lst:
		if l > i:
			result.append(i + length - l);
		else:
			result.append(i - l);
		i += 1;
	if result and command != None:
		dic[command](result);
	return result;

def command_ra_cost(cur, listA):
	cost = 0;
	tmp = ra(listA);
	return calc_cost(tmp);

def command_rra_cost(a, b):
	return 0;

def print_cost(A):
	print("[cost]")
	cur = calc_cost(A);
	print("cur   : " , cur)
	cur_cost = sum(cur);
	print(" cost : " , cur_cost)

	_ra = calc_cost(A, ra);
	print("ra    : " , _ra)
	_ra_cost = sum(_ra);
	print(" cost : " , _ra_cost)

	_rra = calc_cost(A, rra);
	print("rra    : " , _rra)
	_rra_cost = sum(_rra);
	print(" cost : " , _rra_cost)

	_sa = calc_cost(A, sa);
	print("sa    : " , _sa)
	_sa_cost = sum(_sa);
	print(" cost : " , _sa_cost)

"""
	_pushA = calc_cost(A, pushA);
	print("pushA    : " , _pushA)
	_pushA_cost = sum(_pushA);
	print(" cost : " , _pushA_cost)

	_pushB = calc_cost(A, pushB);
	print("pushB    : " , _pushB)
	_pushB_cost = sum(_pushB);
	print(" cost : " , _pushB_cost)
"""

global dic;
global command;
dic = {ra:rra, rra:ra, pushA:pushB, pushB:pushA, sa:sa};
command = {'sa':sa, 'ra':ra, 'rra':rra}
A = deque(range(1, 5))
B = []
cur_list = []

random.shuffle(A)
while (1) :
	print(A)
	print_cost(A)
	s = input("명령어 : ")
	if s in command:
		command[s](A);
