#!/usr/bin/sh

for domain in $(find /etc/acme -type d -not -path /etc/acme); do
    echo "Checking certificate expiry date for ${domain##*/}…"
    openssl x509 -noout -checkend 2592000 -in ${domain}/fullchain.pem > /dev/null 2>&1 && echo "Certificate not expiring within 30 days, skipping." && continue
    echo "Renewing certificate for ${domain##*/}…"
    /usr/bin/acme-tiny --account-key /etc/acme/accountkey.pem --csr ${domain}/csr.pem --acme-dir /var/lib/acme/ > ${domain}/fullchain_new.pem || exit
done
