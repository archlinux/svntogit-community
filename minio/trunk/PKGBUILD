# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Daniel Maslowski <info@orangecms.org>

pkgname=minio
pkgver=2021.11.09
_timever=T03:21:45Z
_pkgver="${pkgver//./-}${_timever//:/-}"
pkgrel=1
pkgdesc='Object storage server compatible with Amazon S3'
arch=('x86_64')
url='https://minio.io'
license=('APACHE')
depends=('glibc')
makedepends=('go' 'git')
options=('!strip')
source=(git+https://github.com/minio/minio.git#tag=RELEASE.${_pkgver}
        minio.conf
        minio.service
        minio.sysusers)
backup=('etc/minio/minio.conf')
sha512sums=('SKIP'
            '9fb09d19af9d7a00e4680cd92d208ddd44ce52328f6efee68d7ee47f591cbe77ee88ce139a677bcf8836de0643de18c6c7c4005d50b0056f9b861c3d595e5233'
            '59aa13b47494564c8eea23dd48fdccef0e65adc0defd4bbd9ca039fd602de0791e1311e444bddca71a1bec7a58cb4eaafad09a8d9ae61eb1e534287dfdf610c2'
            '7e4617aed266cf48a2ff9b0e80e31641d998537c78d2c56ce97b828cfc77d96dbf64728d4235dac7382d6e5b201388bef6722959302de5e2298d93f4ec1e0e63')

build() {
  export CGO_LDFLAGS="${LDFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export GOFLAGS="-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw"

  cd minio

  sed -i "s/Version.*/Version = \"${pkgver//./-}${_timever}\"/g" cmd/build-constants.go
  sed -i "s/ReleaseTag.*/ReleaseTag = \"RELEASE.${_pkgver}\"/g" cmd/build-constants.go
  sed -i "s/CommitID.*/CommitID = \"$(git rev-parse HEAD)\"/g" cmd/build-constants.go

  go build .
}

package() {
  install -dm750 -o 103 -g 103 "${pkgdir}/srv/minio"
  install -dm750 -o 103 -g 103 "${pkgdir}/var/lib/minio"

  install -Dm755 minio/minio "${pkgdir}/usr/bin/minio"
  install -Dm600 "${srcdir}/minio.conf" "${pkgdir}/etc/minio/minio.conf"
  install -Dm644 "${srcdir}/minio.service" "${pkgdir}/usr/lib/systemd/system/minio.service"
  install -Dm644 "${srcdir}/minio.sysusers" "${pkgdir}/usr/lib/sysusers.d/minio.conf"
}
