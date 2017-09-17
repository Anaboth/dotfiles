mem () {
	used=$(free -m | grep Mem | awk '{print $3 + $5}')

	total=$(free -m | grep Mem | awk '{print $2}')

	echo RAM $used MiB / $total MiB
}

up () {
	_up=$(awk '{printf("%d:%d:%02d:%02d",($1/60/60/24),($1/60/60/24/7),($1/60/60%24),($1/60%60))}' /proc/uptime)

	echo UP $_up
}

packages () {
	qnt=$(pacman -Qq | wc -l)
	upts=$(checkupdates | wc -l)
	#upts="0"

	echo Packages $qnt/$upts
}

while true; do
xsetroot -name "$(mem) :: $(up) :: $(packages) :: $(date +'%a %b %d %H:%M %Y') :: An it harm none, do what ye will" ;
sleep 1;
done &
