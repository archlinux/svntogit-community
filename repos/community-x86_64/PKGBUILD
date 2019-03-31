# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=runc
pkgver=1.0.0rc7
pkgrel=1
pkgdesc='CLI tool for managing OCI compliant containers'
arch=(x86_64)
url='https://runc.io/'
license=(Apache)
depends=(libseccomp)
makedepends=(git go-pie go-md2man)
_commit=69ae5da6afdcaaf38285a10b36f362e41cb298d6  # tags/v1.0.0-rc7^0
source=("git+https://github.com/opencontainers/runc.git#commit=$_commit?signed")
validpgpkeys=("5F36C6C61B5460124A75F5A69E18AA267DDB8DB4")
sha256sums=('SKIP')

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
  export EXTRA_FLAGS="-gcflags all=-trimpath=${PWD} -asmflags all=-trimpath=${PWD}"
  export GOPATH="$srcdir"
  export EXTRA_LDFLAGS="-extldflags ${LDFLAGS}"
  export BUILDTAGS='seccomp'
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
