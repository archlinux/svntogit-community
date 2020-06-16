# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lukas Grossar <lukas.grossar@gmail.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>
# Contributor: Wayne Cheng <waynethecheng@gmail.com>
# Contributor: Matthias Lisin <ml@visu.li>

pkgname=helm
pkgver=3.2.4
pkgrel=1
pkgdesc="The Kubernetes Package Manager"
arch=("x86_64")
url="https://helm.sh/"
license=("Apache")
depends=('glibc')
makedepends=("go" "git")
_commit=0ad800ef43d3b826f31a5ad8dfbb4fe05d143688
source=("git+https://github.com/helm/helm.git#commit=$_commit?signed")
validpgpkeys=('672C657BE06B4B30969C4A57461449C25E36B98E'
              '967F8AC5E2216F9F4FD270AD92AA783CBAAE8E3B')
sha256sums=('SKIP')

pkgver() {
  cd "${pkgname}"
  git describe --tags | sed 's/^v//;s/-/+/g'
}

build() {
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make GOFLAGS="-buildmode=pie -trimpath"
}

check(){
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make GOFLAGS="-buildmode=pie -trimpath" test-unit
}

package(){
    cd "${pkgname}"
    install -Dm755 bin/helm -t "$pkgdir/usr/bin"
    bin/helm completion bash | install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/helm"
    bin/helm completion zsh | install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_helm"
}
