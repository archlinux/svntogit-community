# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2017.11.22
_pkgver="${pkgver//./-}T19-55-46Z"
pkgrel=2
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
sha512sums=('d40a205b631d5d1b29b90fc4afff4af07072a7ea27069d9f55a6c54f6a5418328dd44d8f5be2882ac7fdb1f969936de70cd51859d0f5c218c1223a98738e5e2b'
            '630a5d109409074b67be71b663a43ad09104121cca3637bb0542df19e375023bff7d7e2cbf39e52cc3cd060d41c363a90bd4ff7734aed1a5ca43a600f6d6d275'
            '1c6ea217ea8aac93c9d1e05ad0b6c2108fe3d6367fa6a55acc480b8667996bbb59743e2f7e354c5257fc68bffc18cc44a48c4a82eee293abddcdc7962e63e50b'
            '1399f1ad39972a7c43d37bad3acf00d7fcaeec6030f8316be187a0bb2d84a1096bfc5236c976ed63f5fe86b92ddd6be8b188aa58aa4b7fbfe742337001800c75')

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
