#!/bin/bash

openssl req -nodes -new -x509 -keyout /etc/nginx/ssl/naorakot.42.fr.key -out /etc/nginx/ssl/naorakot.42.fr.crt -subj "/C=US/ST=State/L=City/O=company/OU=Com/CN=naorakot.42.fr"

#then here the chmods, 444 for now, experiment with key access later
