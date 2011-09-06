# Maintainer: Daenyth <Daenyth+Arch AT gmail DOT com>
# Contributor: Daenyth <Daenyth+Arch AT gmail DOT com>
pkgname=pkgtools
pkgver=23
pkgrel=1
pkgdesc="A collection of scripts for Arch Linux packages"
arch=('i686' 'x86_64')
url="http://bbs.archlinux.org/viewtopic.php?pid=384196"
license=('GPL')
source=(v$pkgver::http://github.com/Daenyth/pkgtools/tarball/v$pkgver)
backup=('etc/pkgtools/newpkg.conf' 'etc/pkgtools/pkgfile.conf' 'etc/pkgtools/spec2arch.conf')
install=pkgtools.install
provides=(newpkg pkgfile)
depends=('bash>=4' 'pcre' 'libarchive' 'python')
optdepends=('cron: For pkgfile --update entry'
            'abs: Provides proto packaging files for newpkg'
            'python-yaml: for gem2arch'
            'python2: for pkgconflict')
md5sums=('5361111e31741f8d7ff8ca45c7996b6b')

build() {
  cd "$srcdir/Daenyth-$pkgname"-*

  make
  make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
