# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Althorion <althorion@protonmail.com>
# Contributor: Jordan Day <jordanday444 at gmail.com>

pkgname=ttf-jetbrains-mono
pkgver=2.304
pkgrel=1
pkgdesc='Typeface for developers, by JetBrains'
arch=(any)
url='https://jetbrains.com/lp/mono'
license=(custom:OFL)
source=("https://github.com/JetBrains/JetBrainsMono/releases/download/v$pkgver/JetBrainsMono-$pkgver.zip")
b2sums=('c54913d1d7f11150afeb2974238ee26f09be5ea2b1db2510c00bafb2ae0d807d6ca64d4fcef5dfc95d524bb4f2f3324243fc6a693bd2b81c79820f48cb1e9909')

package() {
  find fonts/ttf -type f -name '*.ttf' -exec \
    install -Dm644 -t "$pkgdir/usr/share/fonts/TTF" {} \;
  install -Dm644 OFL.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
