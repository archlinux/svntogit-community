#!/usr/bin/sh

# Read through domains
for domain in $(find /etc/acme -type d -not -path /etc/acme); do
    if [ -f ${domain}/fullchain_new.pem ]; then # The certificate was renewed
        echo "Replacing certificate and fixing permissions for ${domain##*/}…"
        mv ${domain}/fullchain{_new,}.pem
        chown root:root ${domain}/fullchain.pem
        chmod 444 ${domain}/fullchain.pem
        # Splitting for OCSP needs
        FULLCHAIN=$(<${domain}/fullchain.pem)
        echo "${FULLCHAIN%%-----END CERTIFICATE-----*}-----END CERTIFICATE-----" > ${domain}/cert.pem
        echo -e "${FULLCHAIN#*-----END CERTIFICATE-----}" | sed '/./,$!d' > ${domain}/chain.pem
    fi
    # Regenerate answers for OCSP stapling (whether or not the certificate has been renewed)
    echo "Regenerating OCSP priming for ${domain##*/}…"
    openssl ocsp -noverify -no_nonce -respout ${domain}/ocsp.der -issuer ${domain}/chain.pem -cert ${domain}/cert.pem -url $(openssl x509 -noout -ocsp_uri -in ${domain}/cert.pem)
done
