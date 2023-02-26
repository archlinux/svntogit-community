# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: slubman <slubman.dndd@laposte.net>

pkgname=afpfs-ng
pkgver=0.8.2
_commit=e107bd4939d9332e5eb70ab0c09479b7a87d18e2
pkgrel=3
pkgdesc="A client for the Apple Filing Protocol (AFP)"
url="http://alexthepuffin.googlepages.com/"
license=('GPL')
depends=('gmp' 'fuse' 'libgcrypt')
makedepends=('git')
arch=('x86_64')
source=(
    "$pkgname::git+https://github.com/simonvetter/afpfs-ng.git#commit=$_commit"
)
sha256sums=('SKIP')

build() {
    cd "$pkgname"
    CFLAGS+=' -fcommon' # https://wiki.gentoo.org/wiki/Gcc_10_porting_notes/fno_common
    ./configure --prefix=/usr
    make
}

package() {
    cd "$pkgname"
    make DESTDIR="$pkgdir" install

    # install headers
    cd include
    for header in afpfs-ng/*.h; do
        install -Dm644 "$header" "$pkgdir/usr/include/$header"
    done
}
