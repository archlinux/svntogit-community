# Maintainer: Sébastien "Seblu" Luttringer

pkgname=runc
pkgver=1.0.0rc5+168+g079817cc
pkgrel=1
pkgdesc='CLI tool for managing OCI compliant containers'
arch=(x86_64)
url='https://runc.io/'
license=(Apache)
depends=(glibc libseccomp)
makedepends=(git go-pie go-md2man)
_commit=079817cc26ec5292ac375bb9f47f373d33574949  # master
source=(git+https://github.com/opencontainers/runc.git#commit=$_commit)
md5sums=('SKIP')

pkgver() {
  cd runc
  git describe | sed 's/^v//;s/-//;s/-/+/g'
}

prepare() {
  mkdir -p src/github.com/opencontainers
  cp -r runc src/github.com/opencontainers/
}

build() {
  cd src/github.com/opencontainers/runc
  GOPATH="$srcdir" BUILDTAGS='seccomp' make runc man
}

package() {
  cd src/github.com/opencontainers/runc

  install -Dm755 runc "$pkgdir/usr/bin/runc"
  install -Dm644 contrib/completions/bash/runc \
    "$pkgdir/usr/share/bash-completion/completions/runc"
  
  install -d "$pkgdir/usr/share/man/man8"
  install -m644 man/man8/*.8 "$pkgdir/usr/share/man/man8"
}
