# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2018.01.02
_pkgver="${pkgver//./-}T23-07-00Z"
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
sha512sums=('6bfb713ef346a49e3a2edfedb55463c2f809309d17c42727890815054ea363e32404970869c0ed2dfda5b7eb40357abd5ef54323f18870448f452d68a4bee74c'
            '630a5d109409074b67be71b663a43ad09104121cca3637bb0542df19e375023bff7d7e2cbf39e52cc3cd060d41c363a90bd4ff7734aed1a5ca43a600f6d6d275'
            '1c6ea217ea8aac93c9d1e05ad0b6c2108fe3d6367fa6a55acc480b8667996bbb59743e2f7e354c5257fc68bffc18cc44a48c4a82eee293abddcdc7962e63e50b'
            '0832f0927da94c1c552dcd1a0a98a56b4447c0fc5f0e6d3b498f720ae7512fcfd5261b158775817f8c75ea43c052434ebadceb385d722aaea58a12fdb2a401ed')

build() {
  export GOPATH="${srcdir}/go"
  mkdir -p "${GOPATH}/src/github.com/minio"
  mv "${srcdir}/minio-RELEASE.${_pkgver}" "${GOPATH}/src/github.com/minio/minio"
  cd "${GOPATH}/src/github.com/minio/minio"
  go build
}

package() {
  install -dm750 -o 103 -g 103 "${pkgdir}/srv/minio"

  export GOPATH="${srcdir}/go"
  cd "${GOPATH}/src/github.com/minio/minio"
  install -Dm755 "${pkgname}" "${pkgdir}/usr/bin/${pkgname}"
  install -Dm644 "${srcdir}/minio.conf" "${pkgdir}/etc/minio/${pkgname}.conf"
  install -Dm644 "${srcdir}/minio.service" "${pkgdir}/usr/lib/systemd/system/${pkgname}.service"
  install -Dm644 "${srcdir}/minio.sysusers" "${pkgdir}/usr/lib/sysusers.d/${pkgname}.conf"
}
