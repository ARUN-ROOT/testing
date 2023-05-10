main:
	gcc -o client 02_client.c
run:
	./client
clean:
	rm 01_server.c 02_client.c ipaddress.txt
