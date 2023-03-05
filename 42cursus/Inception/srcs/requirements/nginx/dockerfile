FROM alpine:3.17.2

# apk install
ENV NGINX_VER="1.22.1-r0"

RUN apk update
RUN apk add nginx=${NGINX_VER} openssl

# nginx
COPY conf/default.conf /etc/nginx/http.d
RUN echo "daemon off;" >> /etc/nginx/nginx.conf

# nginx:ssl
ENV SSL_PRIVATE_KEY="/var/www/ssl/nginx-ssl.key"
ENV SSL_PUBLIC_KEY="/var/www/ssl/nginx-ssl.crt"
ENV SSL_CSR="/var/www/ssl/nginx-ssl.csr"
ENV SSL_REQ_CONF="/tmp/ssl_req_info.conf"

COPY conf/ssl_req_info.conf /tmp

RUN mkdir -p /var/www/ssl
RUN openssl genrsa 2048 > ${SSL_PRIVATE_KEY}
RUN openssl req -new -key ${SSL_PRIVATE_KEY} -out ${SSL_CSR} -config ${SSL_REQ_CONF}
RUN openssl req -x509 -days 365 -key ${SSL_PRIVATE_KEY} -in ${SSL_CSR} -out ${SSL_PUBLIC_KEY} -days 365 -config ${SSL_REQ_CONF}

# port
EXPOSE 443

ENTRYPOINT [ "nginx" ]
