#!/bin/sh

swtpm socket --tpm2 --server port=2321 --ctrl type=tcp,port=2322 --flags not-need-init --tpmstate dir="$PWD" &
tpm2-abrmd --session --tcti swtpm &

export TPM2OPENSSL_TCTI="tabrmd:bus_type=session"
export TPM2TOOLS_TCTI="$TPM2OPENSSL_TCTI"

make --jobs=1 check

kill $(jobs -p)
