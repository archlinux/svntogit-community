# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Richard Bradfield <bradfier@fstab.me>

pkgname=github-cli
pkgver=2.22.0
pkgrel=1
pkgdesc="The GitHub CLI"
arch=("x86_64")
url="https://github.com/cli/cli"
license=("MIT")
depends=("glibc" "mailcap")
makedepends=("go" "git")
checkdepends=("openssh")
optdepends=("git: To interact with repositories")
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha256sums=('fc9aacccd6a07da6fb2cfa57e2a08d72bdc3a3476f6abec6250cda1e59ae6e16')

prepare() {
    cd "cli-${pkgver}"
    # TODO: These tests invoke the TTY and our container *really* does not like that
    rm pkg/cmd/auth/login/login_test.go
    # Drop tests that invoking 3rd party server processes
    rm pkg/cmd/search/shared/shared_test.go \
       internal/codespaces/rpc/invoker_test.go
}

build() {
    cd "cli-$pkgver"

    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export CGO_ENABLED=0
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw -ldflags=-linkmode=external"

    make GH_VERSION="v$pkgver" bin/gh manpages
    bin/gh completion -s bash | install -Dm644 /dev/stdin share/bash-completion/completions/gh
    bin/gh completion -s zsh | install -Dm644 /dev/stdin share/zsh/site-functions/_gh
    bin/gh completion -s fish | install -Dm644 /dev/stdin share/fish/vendor_completions.d/gh.fish
}

check(){
    cd "cli-$pkgver"
    make test
}

package() {
    cd "cli-$pkgver"
    make DESTDIR="${pkgdir}" prefix="/usr" install
    cp -r share/ "$pkgdir"/usr
    install -Dm644 "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
    install -Dm644 "README.md" "$pkgdir/usr/share/doc/$pkgname/README.md"
}
