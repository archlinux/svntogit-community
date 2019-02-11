# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer

pkgname=runc
pkgver=1.0.0rc6
pkgrel=1
pkgdesc='CLI tool for managing OCI compliant containers'
arch=(x86_64)
url='https://runc.io/'
license=(Apache)
depends=(libseccomp)
makedepends=(git go-pie go-md2man)
_commit=ccb5efd37fb7c86364786e9137e22948751de7ed
source=("git+https://github.com/opencontainers/runc.git#commit=$_commit?signed"
		"0001-nsenter-clone-proc-self-exe-to-avoid-exposing-host-b.patch")
validpgpkeys=("5F36C6C61B5460124A75F5A69E18AA267DDB8DB4")
sha256sums=('SKIP'
            '327ee5b857062d53527701e70ae86a0614732e11b9000ab7a69f9e32981717c6')

pkgver() {
  cd runc
  git describe | sed 's/^v//;s/-//;s/-/+/g'
}

prepare() {
  mkdir -p src/github.com/opencontainers
  cp -r runc src/github.com/opencontainers/
  cd src/github.com/opencontainers/runc
  patch -Np1 -i "${srcdir}/0001-nsenter-clone-proc-self-exe-to-avoid-exposing-host-b.patch"
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
