# Maintainer: Daenyth <Daenyth+Arch AT gmail DOT com>
# Contributor: Daenyth <Daenyth+Arch AT gmail DOT com>
pkgname=pkgtools
pkgver=19
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
md5sums=('0593df5f7f35a23532cdbfe006c50311')


build() {
  cd "$srcdir/Daenyth-$pkgname"-*

  make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
