# Сдвинуть модель по y на -0.25
f_in = open('model.obj')
f_out = open('model1.obj', 'w')

for line in f_in:
    if line.startswith('v '):
        content = line.split(' ')
        res = 'v ' + content[1] + ' ' + str(float(content[2]) - 0.25) + ' ' + content[3]
        f_out.write(res)
    else:
        f_out.write(line)