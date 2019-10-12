# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2019.10.11
_timever=T00:38:09Z
_pkgver="${pkgver//./-}${_timever//:/-}"
pkgrel=1
pkgdesc='Object storage server compatible with Amazon S3'
arch=('x86_64')
url='https://minio.io'
license=('APACHE')
depends=('glibc')
makedepends=('go-pie' 'git')
options=('!strip')
source=(git+https://github.com/minio/minio.git#tag=RELEASE.${_pkgver}
        minio.conf
        minio.service
        minio.sysusers)
backup=('etc/minio/minio.conf')
sha512sums=('SKIP'
            '630a5d109409074b67be71b663a43ad09104121cca3637bb0542df19e375023bff7d7e2cbf39e52cc3cd060d41c363a90bd4ff7734aed1a5ca43a600f6d6d275'
            '59aa13b47494564c8eea23dd48fdccef0e65adc0defd4bbd9ca039fd602de0791e1311e444bddca71a1bec7a58cb4eaafad09a8d9ae61eb1e534287dfdf610c2'
            '7e4617aed266cf48a2ff9b0e80e31641d998537c78d2c56ce97b828cfc77d96dbf64728d4235dac7382d6e5b201388bef6722959302de5e2298d93f4ec1e0e63')

build() {
  export GOPATH="${srcdir}/go"
  mkdir -p "${GOPATH}/src/github.com/minio"
  mv "${srcdir}/minio" "${GOPATH}/src/github.com/minio/minio"
  cd "${GOPATH}/src/github.com/minio/minio"
  sed -i "s/Version.*/Version = \"${pkgver//./-}${_timever}\"/g" cmd/build-constants.go
  sed -i "s/ReleaseTag.*/ReleaseTag = \"RELEASE.${_pkgver}\"/g" cmd/build-constants.go
  sed -i "s/CommitID.*/CommitID = \"$(git rev-parse HEAD)\"/g" cmd/build-constants.go
  GO111MODULE=on go build
}

package() {
  install -dm750 -o 103 -g 103 "${pkgdir}/srv/minio"
  install -dm750 -o 103 -g 103 "${pkgdir}/var/lib/minio"

  cd "${srcdir}/go/src/github.com/minio/minio"
  install -Dm755 minio "${pkgdir}/usr/bin/minio"
  install -Dm644 "${srcdir}/minio.conf" "${pkgdir}/etc/minio/minio.conf"
  install -Dm644 "${srcdir}/minio.service" "${pkgdir}/usr/lib/systemd/system/minio.service"
  install -Dm644 "${srcdir}/minio.sysusers" "${pkgdir}/usr/lib/sysusers.d/minio.conf"
}
