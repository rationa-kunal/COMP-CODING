
def angle(hr, mi):
	if hr==12:
		hr=0
	if mi==60:
		mi=0
	hr_ang = 0.5 * (hr*60 + mi)
	mi_ang = 6*mi

	ang = abs(hr_ang - mi_ang)

	return min(ang, 360-ang)

new_hr = int(input())
log = float(input())

time_per = (new_hr*60/360)
time = time_per*log
_time = time%60
time = (time//60)%12

print('%.2f' % angle(time, _time))