# Maintainer : schuay <jakob.gruber@gmail.com>
# Contributor : kevin <kevin@archlinux.org>
# Contributor : Christian Schmidt <mucknert@gmx.net>
# Contributor : Markus Meissner <markus@meissna.de>
# Contributor : Nick Erdmann <erdmann@date.upb.de>

pkgname=nethack
pkgver=3.6.6
pkgrel=2
pkgdesc='A single player dungeon exploration game'
arch=('x86_64')
url="https://www.nethack.org/index.html"
license=('custom')
depends=('filesystem' 'ncurses' 'gzip')
install=nethack.install
source=(
  "https://www.nethack.org/download/${pkgver}/${pkgname}-${pkgver//.}-src.tgz"
  "${pkgname}.tmpfiles"
)
sha512sums=('579fde93a37a1b5df637d5bac2601194beeb455c175fbe3ef89342122c8567bb8221ce60d8a6168e6b45c67ade7d7b09c86bf202c8cbe2d6294d276be3e53055'
            '277503212c0b2f9344ef6493ecbff6d0aab6ecf148885db23bbb55d9eebdcd0f48f4abd2e42aa7aed8fd8d426e48f011912e2d3c1d7a85f407846f8a7be84ee9')
b2sums=('7b4b12f3a711785c86208dab83f9de725c33470e056ee57e6d96c3a68f06c1d0d98343ed82eca669986361d0663ddbe56d9a74d9cb45b42bf005c2f323b3cd79'
        'f61c7e9e5a1d1ab4e49447e2520c93abeca2b99dc21ce138f2b5fe2e371164bb5f98f21a50eead0dc1087a5a65b8298b9566d89b5b4a2762625932ccc411f378')

_builddir="NetHack-NetHack-3.6.6_Released"

prepare() {
  cd $_builddir

  sed -e 's|^/\* \(#define LINUX\) \*/|\1|' \
      -e 's|^/\* \(#define TIMED_DELAY\) \*/|\1|' -i include/unixconf.h

  # we are setting up for setgid games, so modify all necessary permissions
  # to allow full access for groups

  sed -e '/^HACKDIR/ s|/games/lib/\$(GAME)dir|/var/games/nethack/|' \
      -e '/^SHELLDIR/ s|/games|/usr/bin|' \
      -e '/^VARDIRPERM/ s|0755|0775|' \
      -e '/^VARFILEPERM/ s|0600|0664|' \
      -e '/^GAMEPERM/ s|0755|02755|' \
      -e 's|\(DSYSCF_FILE=\)\\"[^"]*\\"|\1\\"/var/games/nethack/sysconf\\"|' \
      -e 's|\(DHACKDIR=\)\\"[^"]*\\"|\1\\"/var/games/nethack/\\"|' -i sys/unix/hints/linux

  sed -e 's|^#GAMEUID.*|GAMEUID = root|' \
      -e 's|^#GAMEGRP.*|GAMEGRP = games|' \
      -e '/^FILEPERM\s*=/ s|0644|0664|' \
      -e '/^DIRPERM\s*=/ s|0755|0775|' -i sys/unix/Makefile.top

  sed -e "/^MANDIR\s*=/s|/usr/man/man6|$pkgdir/usr/share/man/man6|" -i sys/unix/Makefile.doc

}

build(){
  cd $_builddir/sys/unix
  sh setup.sh hints/linux

  cd "$srcdir"/$_builddir
  make
}
  
package() {
  cd $_builddir

  install -dm755 "$pkgdir"/usr/share/{man/man6,doc/nethack}
  install -dm775 "$pkgdir"/var/games/
  make PREFIX="$pkgdir" -j1 install manpages # Multi-threaded builds fail.
  sed -e "s|HACKDIR=$pkgdir/|HACKDIR=/|" \
      -e 's|HACK=$HACKDIR|HACK=/usr/lib/nethack|' \
      -i "$pkgdir"/usr/bin/nethack

  install -dm755 "$pkgdir"/usr/lib/nethack
  mv "$pkgdir"/var/games/nethack/{nethack,recover} "$pkgdir"/usr/lib/nethack/

  install -vDm 644 ../${pkgname}.tmpfiles "${pkgdir}/usr/lib/tmpfiles.d/${pkgname}.conf"

  install -Dm644 doc/Guidebook.txt "$pkgdir"/usr/share/doc/nethack/Guidebook.txt
  install -Dm644 dat/license "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

