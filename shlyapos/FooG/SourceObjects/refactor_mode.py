# Сдвинуть модель по y на -0.25
f_in = open('sphere.obj')
f_out = open('sphere1.obj', 'w')

for line in f_in:
    if line.startswith('v '):
        content = line.split(' ')
        res = 'v ' + str(float(content[1]) / 20) + ' ' + str(float(content[2]) / 20) + ' ' + str(float(content[3]) / 20 + 0.1) + '\n'
        f_out.write(res)
    else:
        f_out.write(line)