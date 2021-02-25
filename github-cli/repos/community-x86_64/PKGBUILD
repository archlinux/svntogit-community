# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Richard Bradfield <bradfier@fstab.me>

pkgname=github-cli
pkgver=1.6.2
pkgrel=1
pkgdesc="The GitHub CLI"
arch=("x86_64")
url="https://github.com/cli/cli"
license=("MIT")
depends=("glibc" "mailcap")
makedepends=("go" "git")
optdepends=("git: To interact with repositories")
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha256sums=('8cc3cafb85e1234f61ef5c4468d07307142fa0cc99bdc7452251cf1cac9b38ae')


prepare() {
    cd "cli-${pkgver}"
    # TODO: These tests invoke the TTY and our container *really* does not like that
    rm pkg/cmd/auth/login/login_test.go
}

build() {
    cd "cli-$pkgver"

    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw -ldflags=-linkmode=external"

    make GH_VERSION="v$pkgver" bin/gh manpages
    bin/gh completion -s bash | install -Dm644 /dev/stdin share/bash-completion/completions/gh
    bin/gh completion -s zsh | install -Dm644 /dev/stdin share/zsh/site-functions/_gh
    bin/gh completion -s fish | install -Dm644 /dev/stdin share/fish/vendor_completions.d/gh.fish
}

check(){
    cd "cli-$pkgver"
    # export CGO_CPPFLAGS="${CPPFLAGS}"
    # export CGO_CFLAGS="${CFLAGS}"
    # export CGO_CXXFLAGS="${CXXFLAGS}"
    # export CGO_LDFLAGS="${LDFLAGS}"
    # export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw -ldflags=-linkmode=external"
    make test
}

package() {
    cd "cli-$pkgver"
    make DESTDIR="${pkgdir}" prefix="/usr" install
    install -Dm644 "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
    install -Dm644 "README.md" "$pkgdir/usr/share/doc/$pkgname/README.md"
}
