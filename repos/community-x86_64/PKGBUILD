# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lukas Grossar <lukas.grossar@gmail.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>
# Contributor: Wayne Cheng <waynethecheng@gmail.com>
# Contributor: Matthias Lisin <ml@visu.li>

pkgname=helm
pkgver=3.1.2
pkgrel=3
pkgdesc="The Kubernetes Package Manager"
arch=("x86_64")
url="https://helm.sh/"
license=("Apache")
depends=('glibc')
makedepends=("go" "git")
source=("git+https://github.com/helm/helm.git#tag=v$pkgver?signed")
validpgpkeys=('672C657BE06B4B30969C4A57461449C25E36B98E')
sha256sums=('SKIP')

prepare() {
    cd "${pkgname}"

    # fix: update unit test for go 1.14 error string change (#7835)
    # https://github.com/helm/helm/pull/7835
    git cherry-pick -n 3706aa7ca666fda6d8301c55118fa1c092f124a2 

    # Repair failing unit tests - failure caused by os.Stat return values for directory size on Linux.
    # https://github.com/helm/helm/pull/7189
    git cherry-pick -n e3976ab7a286ecbe1038a725fbc4149b95267abf
}

build() {
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    make GOFLAGS="-buildmode=pie -trimpath"
}

check(){
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    make GOFLAGS="-buildmode=pie -trimpath" test-unit
}

package(){
    cd "${pkgname}"
    install -Dm755 bin/helm -t "$pkgdir/usr/bin"
    bin/helm completion bash | install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/helm"
    bin/helm completion zsh | install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_helm"
}
