# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=runc
pkgver=1.1.3
pkgrel=2
pkgdesc='CLI tool for managing OCI compliant containers'
arch=(x86_64)
url='https://runc.io/'
license=(Apache)
provides=('oci-runtime')
depends=(libseccomp)
makedepends=(git go go-md2man)
optdepends=(
  'criu: checkpoint support'
)
source=("${pkgname}-${pkgver}.tar.xz::https://github.com/opencontainers/runc/releases/download/v${pkgver}/runc.tar.xz"
        "${pkgname}-${pkgver}.tar.xz.sig::https://github.com/opencontainers/runc/releases/download/v${pkgver}/runc.tar.xz.asc")
validpgpkeys=("5F36C6C61B5460124A75F5A69E18AA267DDB8DB4"
			  "C9C370B246B09F6DBCFC744C34401015D1D2D386")
sha256sums=('2db1f3a01ffd2f8fa3a259b9b512ca7d4dbf89be5765cc58d306e45658668453'
            'SKIP')

prepare() {
  mkdir -p src/github.com/opencontainers
  cp -r runc-${pkgver} src/github.com/opencontainers/runc
}

build() {
  cd src/github.com/opencontainers/runc
  export GOPATH="$srcdir"
  export BUILDTAGS='seccomp apparmor'
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export GOFLAGS="-trimpath -mod=readonly -modcacherw"
  make runc man
}

package() {
  cd src/github.com/opencontainers/runc

  install -Dm755 runc "$pkgdir/usr/bin/runc"
  install -Dm644 contrib/completions/bash/runc \
    "$pkgdir/usr/share/bash-completion/completions/runc"
  
  install -d "$pkgdir/usr/share/man/man8"
  install -m644 man/man8/*.8 "$pkgdir/usr/share/man/man8"
}
