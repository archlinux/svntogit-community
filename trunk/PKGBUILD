# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Jorge Araya Navarro <jorge@esavara.cr>

pkgname=goimapnotify
pkgver=2.3.5
pkgrel=1
pkgdesc="Execute scripts on IMAP mailbox changes (new/deleted/updated messages) using IDLE, golang version."
url="https://gitlab.com/shackra/goimapnotify"
license=('GPL3')
arch=('x86_64')
depends=('glibc')
makedepends=('git' 'go')
source=("${pkgname}-${pkgver}.tar.gz::${url}/-/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('5e8429f571673ff515f79887e0f844ddc7f87b959450f90cba81920d6d5b7ad4c827650864b8f5ac3f2bfdd21800ffd83cd8d8912a8c4f4fc30753354eb27d6b')

build() {
    cd "${pkgname}-${pkgver}"

    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
    go build -ldflags "-linkmode=external -extldflags=$LDFLAGS"
}

check() {
    cd "${pkgname}-${pkgver}"

    go test ./...
}

package() {
    cd "${pkgname}-${pkgver}"

    install -Dm755 -t "${pkgdir}/usr/bin/" "${pkgname}"
    install -Dm644 -t "${pkgdir}/usr/lib/systemd/user/" goimapnotify@.service
}
