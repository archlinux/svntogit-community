# Maintainer: Daenyth <Daenyth+Arch AT gmail DOT com>
# Contributor: Daenyth <Daenyth+Arch AT gmail DOT com>
pkgname=pkgtools
pkgver=20
pkgrel=1
pkgdesc="A collection of scripts for Arch Linux packages"
arch=(any)
url="http://bbs.archlinux.org/viewtopic.php?pid=384196"
license=('GPL')
source=(http://github.com/Daenyth/pkgtools/tarball/v$pkgver)
backup=('etc/pkgtools/newpkg.conf' 'etc/pkgtools/pkgfile.conf' 'etc/pkgtools/spec2arch.conf')
install=pkgtools.install
provides=(newpkg pkgfile)
depends=('bash>=4')
optdepends=('cron: For pkgfile --update entry'
            'python: For pkgconflict')
md5sums=('dedb2778f157f4928fa4e23a5e87f9e6')

build() {
  cd "$srcdir/Daenyth-$pkgname"-*

  make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
