# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

pkgname=ksh
pkgver=2020.0.0
pkgrel=3
pkgdesc="The Original AT&T Korn Shell"
arch=('x86_64')
url="http://kornshell.org/"
license=('EPL')
makedepends=('meson' 'samurai')
checkdepends=('ed' 'expect' 'openbsd-netcat' 'procps-ng' 'which' 'vi')
provides=('ksh93')
install=ksh.install
source=("https://github.com/att/ast/releases/download/${pkgver}/ksh-${pkgver}.tar.xz"{,.asc}
        "https://github.com/att/ast/commit/d89753b5d38482f4a3f17ba3b7d09ab07cfe7419.patch"
        "CVE-2019-14868.patch")
sha256sums=('3d6287f9ad13132bf8e57a8eac512b36a63ccce2b1e4531d7a946c5bf2375c63'
            'SKIP'
            '7d929d9073a90dc672b2f1eab0f9e80f716e236958bda34b7b992b382552f57f'
            '3e28d2cbe4b6d8d4dc40056aaea78099b2dc95017796395e26f05baae1bbffa2')
b2sums=('29f957c7917d469fe1b322e7ac2c22435c41c226a0d9629d91d81089ab90cb381b578b163be0f424a574663c838f0cfa59357f18dd61381daa4a8d4e383b60eb'
        'SKIP'
        '35c6886ffe362b83d5af42f57b3b6aa6a356e192d374537a61bc25507ca71f5d5419725e750e30980098209f48e87dbe0205ace07437e47b6ae3bbf9eb8424c4'
        'de3e7fd86fb5bddfd85074d1337794a5777c2537baf5d00568beb82ac70ca2d5d6d47902d8ebe5cb32194d426172fbbfba6b4e511013209f0f3aaeec9e07a866')
validpgpkeys=('4BF045ACC726FE4E9DFC1D7762213CE2D3CB82EA') # Siteshwar Vashisht <svashisht@redhat.com>

export NINJA=/usr/bin/samu

prepare() {
    cd "${srcdir}"/ksh-${pkgver}

    # ignore test error on non-debug builds: https://github.com/att/ast/issues/1390
    patch -p1 -i ../d89753b5d38482f4a3f17ba3b7d09ab07cfe7419.patch
    # CVE-2019-14868
    patch -p1 -i ../CVE-2019-14868.patch

    # b_chmod tests known to fail, esp in chroots
    # https://github.com/att/ast/issues/1478
    sed -i -e '/b_chmod/d' src/cmd/ksh93/tests/meson.build
}


build() {
    mkdir -p "${srcdir}"/ksh-${pkgver}/build
    cd "${srcdir}"/ksh-${pkgver}/build

    meson --prefix /usr \
          --buildtype=plain \
          ..
    samu
}

check() {
    cd "${srcdir}"/ksh-${pkgver}/build

    # a couple tests are flaky and may time out
    meson test -t 3 --print-errorlogs
}

package() {
    cd "${srcdir}"/ksh-${pkgver}/build

    DESTDIR="${pkgdir}" samu install
    ln -s ksh "${pkgdir}"/usr/bin/ksh93
}
