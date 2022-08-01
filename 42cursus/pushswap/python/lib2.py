def _pa(A, B):
	if B:
		data = B.popleft();
		A.appendleft(data);

def _pb(A, B):
	if A:
		data = A.popleft();
		B.appendleft(data);

def _sa(A):
	length = len(A);
	if length >= 2:
		tmp = A[0];
		A[0] = A[1];
		A[1] = tmp;
	return A;

def _rra(A):
	result = [];
	if A:
		data = A.pop();
		A.appendleft(data);
		result = list(A);
	return result;

def _ra(A):
	result = [];
	if A:
		data = A.popleft();
		A.append(data);
	return A;

def _sb(B):
	length = len(B);
	if length >= 2:
		tmp = B[0];
		B[0] = B[1];
		B[1] = tmp;
	return A;

def _rrb(B):
	result = [];
	if B:
		data = B.pop();
		B.appendleft(data);
		result = list(B);
	return result;

def _rb(B):
	result = [];
	if B:
		data = B.popleft();
		B.append(data);
	return B;
