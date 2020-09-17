# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lukas Grossar <lukas.grossar@gmail.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>
# Contributor: Wayne Cheng <waynethecheng@gmail.com>
# Contributor: Matthias Lisin <ml@visu.li>

pkgname=helm
pkgver=3.3.2
pkgrel=1
pkgdesc="The Kubernetes Package Manager"
arch=("x86_64")
url="https://helm.sh/"
license=("Apache")
depends=('glibc')
makedepends=("go" "git")
_commit=e5077257b6ca106d1f65652b4ca994736d221ab1 #refs/tags/v3.3.2^{}
source=("git+https://github.com/helm/helm.git#commit=$_commit?signed"
        "go1.15-compat.patch::https://github.com/helm/helm/commit/83a5e620d0acde77502b1f814f749268e8d8ef6e.patch")
validpgpkeys=('672C657BE06B4B30969C4A57461449C25E36B98E'
              '967F8AC5E2216F9F4FD270AD92AA783CBAAE8E3B')
sha256sums=('SKIP'
            '1ae04b9cc2641ef068ce6ad8fe1b29f4177e1451489cd4a7316bf566659d2da8')

pkgver() {
  cd "${pkgname}"
  git describe --tags | sed 's/^v//;s/-/+/g'
}

prepare() {
    cd "${pkgname}"
    patch -Np1 < "$srcdir/go1.15-compat.patch"
}

build() {
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make EXT_LDFLAGS="-linkmode external" GOFLAGS="-buildmode=pie -trimpath"
}

check(){
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make LDFLAGS="-s -w -linkmode external" GOFLAGS="-buildmode=pie -trimpath" test-unit
}

package(){
    cd "${pkgname}"
    install -Dm755 bin/helm -t "$pkgdir/usr/bin"
    bin/helm completion bash | install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/helm"
    bin/helm completion zsh | install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_helm"
}
