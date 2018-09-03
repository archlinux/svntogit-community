# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2018.08.25
_pkgver="${pkgver//./-}T01-56-38Z"
pkgrel=1
pkgdesc='Object storage server compatible with Amazon S3'
arch=('x86_64')
url='https://minio.io'
license=('APACHE')
depends=('glibc')
makedepends=('go-pie')
options=('!strip')
source=(https://github.com/minio/minio/archive/RELEASE.${_pkgver}.tar.gz
        minio.conf
        minio.service
        minio.sysusers)
backup=('etc/minio/minio.conf')
sha512sums=('90eec44636baf08650313e61b378379c67b494fe22196251b8fa25a4ddddd06a370619bd628b256254c41cb0c1ce681b5a3d0b534fd2b4694c784d94fb0713ad'
            '630a5d109409074b67be71b663a43ad09104121cca3637bb0542df19e375023bff7d7e2cbf39e52cc3cd060d41c363a90bd4ff7734aed1a5ca43a600f6d6d275'
            '59aa13b47494564c8eea23dd48fdccef0e65adc0defd4bbd9ca039fd602de0791e1311e444bddca71a1bec7a58cb4eaafad09a8d9ae61eb1e534287dfdf610c2'
            '7e4617aed266cf48a2ff9b0e80e31641d998537c78d2c56ce97b828cfc77d96dbf64728d4235dac7382d6e5b201388bef6722959302de5e2298d93f4ec1e0e63')

build() {
  export GOPATH="${srcdir}/go"
  mkdir -p "${GOPATH}/src/github.com/minio"
  mv "${srcdir}/minio-RELEASE.${_pkgver}" "${GOPATH}/src/github.com/minio/minio"
  cd "${GOPATH}/src/github.com/minio/minio"
  go build
}

package() {
  install -dm750 -o 103 -g 103 "${pkgdir}/srv/minio"
  install -dm750 -o 103 -g 103 "${pkgdir}/var/lib/minio"

  export GOPATH="${srcdir}/go"
  cd "${GOPATH}/src/github.com/minio/minio"
  install -Dm755 "${pkgname}" "${pkgdir}/usr/bin/${pkgname}"
  install -Dm644 "${srcdir}/minio.conf" "${pkgdir}/etc/minio/${pkgname}.conf"
  install -Dm644 "${srcdir}/minio.service" "${pkgdir}/usr/lib/systemd/system/${pkgname}.service"
  install -Dm644 "${srcdir}/minio.sysusers" "${pkgdir}/usr/lib/sysusers.d/${pkgname}.conf"
}
