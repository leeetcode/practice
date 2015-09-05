
def sum(a, b):
    global sum_op_num
    sum_op_num += 1
    return a + b


def dynamic_fib(n):
    global fib_list
    if fib_list[n] != 0:
        return fib_list[n]
    elif n == 3:
        return 3
    elif n == 2:
        return 2
    elif n == 1:
        return 1
    else:
        fib_list[n] = sum(dynamic_fib(n-1), dynamic_fib(n-2))
        return fib_list[n]

def recur_fib(n):
    if n == 3:
        return 3
    elif n == 2:
        return 2
    elif n == 1:
        return 1
    else:
        return sum(recur_fib(n-1), recur_fib(n-2))

sum_op_num = 0
print "recur_fib(30) = " + str(recur_fib(30)) + ", sum_op_num = " + str(sum_op_num)

fib_list = []
for i in range(31):
    fib_list.append(0)
sum_op_num = 0
print "dynamic_fib(30) = " + str(dynamic_fib(30)) + ", sum_op_num = " + str(sum_op_num)

