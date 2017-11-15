# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2017.09.29
_pkgver="${pkgver//./-}T19-16-56Z"
pkgrel=2
pkgdesc='Object storage server compatible with Amazon S3'
arch=('x86_64')
url='https://minio.io'
license=('APACHE')
depends=('glibc')
makedepends=('go-pie')
options=('!strip')
install=minio.install
source=(https://github.com/minio/minio/archive/RELEASE.${_pkgver}.tar.gz
        minio.conf
        minio.service)
backup=('etc/minio/minio.conf')
sha512sums=('eb1ac7294ec54f7e794698ba027e38cef85ed007758ef7b0f3cca1728700ab0a2270deab6591806036d6a935d99168e7c279ee99b122a992286d5ae16636a31d'
            '630a5d109409074b67be71b663a43ad09104121cca3637bb0542df19e375023bff7d7e2cbf39e52cc3cd060d41c363a90bd4ff7734aed1a5ca43a600f6d6d275'
            '1c6ea217ea8aac93c9d1e05ad0b6c2108fe3d6367fa6a55acc480b8667996bbb59743e2f7e354c5257fc68bffc18cc44a48c4a82eee293abddcdc7962e63e50b')

build() {
  export GOPATH="${srcdir}/go"
  mkdir -p "${GOPATH}/src/github.com/minio"
  mv "${srcdir}/minio-RELEASE.${_pkgver}" "${GOPATH}/src/github.com/minio/minio"
  cd "${GOPATH}/src/github.com/minio/minio"
  go build
}

package() {
  install -dm750 "${pkgdir}/srv/minio"

  export GOPATH="${srcdir}/go"
  cd "${GOPATH}/src/github.com/minio/minio"
  install -Dm755 "${pkgname}" "${pkgdir}/usr/bin/${pkgname}"
  install -Dm644 "${srcdir}/minio.conf" "${pkgdir}/etc/minio/${pkgname}.conf"
  install -Dm644 "${srcdir}/minio.service" "${pkgdir}/usr/lib/systemd/system/${pkgname}.service"
}
