# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Jorge Araya Navarro <jorge@esavara.cr>

pkgname=goimapnotify
pkgver=2.3.2
pkgrel=1
pkgdesc="Execute scripts on IMAP mailbox changes (new/deleted/updated messages) using IDLE, golang version."
url="https://gitlab.com/shackra/goimapnotify"
license=('GPL3')
arch=('x86_64')
depends=('glibc')
makedepends=('git' 'go')
source=("${pkgname}-${pkgver}.tar.gz::${url}/-/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('99b5822295700ebdc3a6a80cc5f4c515cb791a506fd6ba146ecd3b6bdcdfb084b61e9e25ae86fbf2d3992f39d928c028c6b144ef96e999bda53786f6e731b412')

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
